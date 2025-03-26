#ifndef ISELECTABLE_H
#define ISELECTABLE_H
#include <string>
namespace Program {
    class ISelectable {
        public:
            virtual int getID() const = 0;
            virtual std::string getName() const = 0;
            virtual ~ISelectable() = default;
        };
        
}

#endif