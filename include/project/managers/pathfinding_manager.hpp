#include "graph.hpp"
#include "scene.hpp"
#include <memory>

class PathfindingManager
{
  public:
    PathfindingManager();
    ~PathfindingManager();

    void Update(std::shared_ptr<Scene> scene);
    void Render() const;
    std::shared_ptr<Graph> GetGraph() const;

  private:
    void GenerateGraphForScene(std::shared_ptr<Scene> scene);
    std::shared_ptr<Graph> graph;
    std::shared_ptr<Scene> scene;
};