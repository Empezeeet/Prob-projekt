#ifndef ISELECTABLE_H
#define ISELECTABLE_H
#include <string>
namespace Program {
    // if it ain't broke don't fix it.
    class ISelectable {
        public:
            virtual int getID() const = 0;
            virtual std::string getName() const = 0;
            virtual ~ISelectable() = default;
        };
        
}

#endif