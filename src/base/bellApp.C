#include "bellApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
bellApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

bellApp::bellApp(InputParameters parameters) : MooseApp(parameters)
{
  bellApp::registerAll(_factory, _action_factory, _syntax);
}

bellApp::~bellApp() {}

void
bellApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"bellApp"});
  Registry::registerActionsTo(af, {"bellApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
bellApp::registerApps()
{
  registerApp(bellApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
bellApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  bellApp::registerAll(f, af, s);
}
extern "C" void
bellApp__registerApps()
{
  bellApp::registerApps();
}
