#include "H2DE/Object/Object.hpp"

H2DE::Object::Object(uint32_t _id) : m_id(_id) {
    m_active = true;
}

void H2DE::Object::destroy() noexcept {
    m_active = false;
}

uint32_t H2DE::Object::get_id() const noexcept {
    return this->m_id;
}