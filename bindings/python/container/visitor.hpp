// Copyright (c) 2018-2019, CNRS
// Authors: Sanghyun Kim <ggory15@snu.ac.kr>

#ifndef __timeopt_python_container_visitor_hpp__
#define __timeopt_python_container_visitor_hpp__

#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <string>

namespace timeopt
{
  namespace python
  {
   
    namespace bp = boost::python;
    
    template<typename Vector, bool NoProxy = false>
    struct VectorPythonVisitor
    : public bp::def_visitor< VectorPythonVisitor<Vector> >
    {
      
      static void expose(const std::string & class_name,
                         const std::string & doc = "")
      {
        bp::class_<Vector>(class_name.c_str(),doc.c_str())
        .def(bp::vector_indexing_suite<Vector,NoProxy>())
        ;
      }
    };
    
  }
}

#endif // ifndef __timeopt_python_container_visitor_hpp__
