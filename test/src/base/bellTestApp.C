//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "bellTestApp.h"
#include "bellApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
bellTestApp::validParams()
{
  InputParameters params = bellApp::validParams();
  return params;
}

bellTestApp::bellTestApp(InputParameters parameters) : MooseApp(parameters)
{
  bellTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

bellTestApp::~bellTestApp() {}

void
bellTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  bellApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"bellTestApp"});
    Registry::registerActionsTo(af, {"bellTestApp"});
  }
}

void
bellTestApp::registerApps()
{
  registerApp(bellApp);
  registerApp(bellTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
bellTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  bellTestApp::registerAll(f, af, s);
}
extern "C" void
bellTestApp__registerApps()
{
  bellTestApp::registerApps();
}
