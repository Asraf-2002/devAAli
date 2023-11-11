#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <raylib.h>
#include "FortuneAlgorithm.h"

const int WINDOW_WIDTH = 1200;
const int  WINDOW_HEIGHT = 900;
const double scale = 50.0;
const myVector2 windowFactor(WINDOW_WIDTH-2*scale, WINDOW_HEIGHT-2*scale);
constexpr float POINT_RADIUS = 5.0f;
constexpr float OFFSET = 1.0f;

std::vector<myVector2> generatePoints(int nbPoints)
{
    uint64_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::cout << "seed: " << seed << '\n';
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    std::vector<myVector2> points;
    for (int i = 0; i < nbPoints; ++i)
        points.push_back(myVector2{static_cast<float>(distribution(generator)), static_cast<float>(distribution(generator))});

    return points;
}

void drawPoint(myVector2 point, Color color){
    point.scaler(windowFactor, scale);
    Vector2 _point = {(float)point.x, (float)point.y};
    DrawCircleV(_point, POINT_RADIUS, color);
}

void drawEdge(myVector2 origin, myVector2 destination, Color color){
    origin.scaler(windowFactor, scale), destination.scaler(windowFactor, scale);
    Vector2 _origin = {(float)origin.x, (float)origin.y};
    Vector2 _destination = {(float)destination.x, (float)destination.y};
    DrawLineV(_origin, _destination, color);
}

void drawPoints(VoronoiDiagram &diagram){
    for (std::size_t i = 0; i < diagram.getNbSites(); ++i)
        drawPoint(diagram.getSite(i)->point, GREEN);
}

void drawDiagram(VoronoiDiagram &diagram)
{
    for (std::size_t i = 0; i < diagram.getNbSites(); ++i)
    {
        const VoronoiDiagram::Site *site = diagram.getSite(i);
        myVector2 center = site->point;
        VoronoiDiagram::Face *face = site->face;
        VoronoiDiagram::HalfEdge *halfEdge = face->outerComponent;
        if (halfEdge == nullptr)
            continue;
        while (halfEdge->prev != nullptr)
        {
            halfEdge = halfEdge->prev;
            if (halfEdge == face->outerComponent)
                break;
        }
        VoronoiDiagram::HalfEdge *start = halfEdge;
        while (halfEdge != nullptr)
        {
            if (halfEdge->origin != nullptr && halfEdge->destination != nullptr)
            {
                myVector2 origin = (halfEdge->origin->point - center) * OFFSET + center;
                myVector2 destination = (halfEdge->destination->point - center) * OFFSET + center;
                drawEdge(origin, destination, RED);
            }
            halfEdge = halfEdge->next;
            if (halfEdge == start)
                break;
        }
    }
}

VoronoiDiagram generateRandomDiagram(std::size_t nbPoints)
{
    // Generate points
    std::vector<myVector2> points = generatePoints(nbPoints);

    // Construct diagram
    FortuneAlgorithm algorithm(points);
    auto start = std::chrono::steady_clock::now();
    algorithm.construct();
    auto duration = std::chrono::steady_clock::now() - start;
    std::cout << "construction: " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms" << '\n';

    // Bound the diagram
    start = std::chrono::steady_clock::now();
    algorithm.bound(Box{-0.05, -0.05, 1.05, 1.05}); // Take the bounding box slightly bigger than the intersection box
    duration = std::chrono::steady_clock::now() - start;
    std::cout << "bounding: " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms" << '\n';
    VoronoiDiagram diagram = algorithm.getDiagram();

    // Intersect the diagram with a box
    start = std::chrono::steady_clock::now();
    bool valid = diagram.intersect(Box{0.0, 0.0, 1.0, 1.0});
    duration = std::chrono::steady_clock::now() - start;
    std::cout << "intersection: " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms" << '\n';
    if (!valid)
        throw std::runtime_error("An error occurred in the box intersection algorithm");

    return diagram;
}

int main()
{
    std::size_t nbPoints = 100;
    VoronoiDiagram diagram = generateRandomDiagram(nbPoints);

    // Initialization
    InitWindow(static_cast<int>(WINDOW_WIDTH), static_cast<int>(WINDOW_HEIGHT), "Fortune's algorithm");

    while (!WindowShouldClose())
    {
        // Update

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        drawDiagram(diagram);
        drawPoints(diagram);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
