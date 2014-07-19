#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <ostream>
#include <string>

using namespace std;

class Exception {

    protected:
        string message;
        const Exception* source;
    public:
        Exception();
        Exception(const string);
        Exception(const Exception*);
        Exception(const string, const Exception*);
        Exception(const Exception& e);
        ~Exception();

        string getMessage() const;
        const Exception& getSource() const;
        bool hasSource() const;

};

ostream& operator<<(ostream&, const Exception&);

#endif  /* EXCEPTION_HPP */

