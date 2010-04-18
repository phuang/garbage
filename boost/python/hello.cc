#include <string>
#include <boost/python.hpp>

using namespace boost::python;

class World
{
public:
    World (std::string msg) : msg (msg) { }
    void set (std::string msg) { this->msg = msg; }
    virtual std::string greet () { return msg; }
    std::string say () {
        return greet ();
    }

public:
    std::string msg;
};

class WorldWrap : public World, public wrapper <World> {
public:
    WorldWrap (std::string msg) : World (msg) { }
    
    std::string greet () {
        if (override f = this->get_override ("greet"))
            return f ();
        return World::greet ();
    }

    std::string default_greet () {
        return this->World::greet ();
    }
};

BOOST_PYTHON_MODULE (hello)
{
    class_<WorldWrap, boost::noncopyable> ("World", init<std::string> ())
        .def_readonly ("msg", &World::msg)
        .def ("greet", &World::greet, &WorldWrap::default_greet)
        .def ("say", &World::greet)
        .def ("set", &World::set)
        ;
}
