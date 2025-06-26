#pragma once
#include "Export.h"
#include <QString>

namespace CDNProtocol {

enum class Role {
    Web,
    AdminUI,
    Db,
    Generator,
    Central
};

inline QString toString(Role r) {
    switch(r) {
    case Role::Web:       return "web";
    case Role::AdminUI:   return "adminUI";
    case Role::Db:        return "db";
    case Role::Generator: return "generator";
    case Role::Central:   return "central";
    }
    return {};
}

} // namespace CDNProtocol
