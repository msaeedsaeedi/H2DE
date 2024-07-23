#include "H2DE/Scene/Scene.hpp"

H2DE::Scene::Scene() : m_object_manager(std::unique_ptr<ObjectManager>(new ObjectManager())) {
}

const float H2DE::Scene::get_delta() const noexcept {
    return m_delta;
}