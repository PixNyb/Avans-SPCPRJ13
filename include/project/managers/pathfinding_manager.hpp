#include "graph.hpp"
#include "point.hpp"
#include "scene.hpp"
#include <memory>
#include <vector>

class PathfindingManager
{
  public:
    PathfindingManager();
    ~PathfindingManager();

    void Update(std::shared_ptr<Scene> scene);
    std::shared_ptr<Graph> GetGraph() const;
    std::vector<std::shared_ptr<Node>> GetPath(Point start, Point end) const;
    std::vector<std::shared_ptr<Node>> GetPath(std::shared_ptr<Node> start, std::shared_ptr<Node> end) const;

  private:
    void GenerateGraphForScene(std::shared_ptr<Scene> scene);
    std::shared_ptr<Graph> graph;
    std::shared_ptr<Scene> scene;
};