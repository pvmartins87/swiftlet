#include "SwiftletApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
SwiftletApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

SwiftletApp::SwiftletApp(InputParameters parameters) : MooseApp(parameters)
{
  SwiftletApp::registerAll(_factory, _action_factory, _syntax);
}

SwiftletApp::~SwiftletApp() {}

void
SwiftletApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<SwiftletApp>(f, af, s);
  Registry::registerObjectsTo(f, {"SwiftletApp"});
  Registry::registerActionsTo(af, {"SwiftletApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
SwiftletApp::registerApps()
{
  registerApp(SwiftletApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
SwiftletApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  SwiftletApp::registerAll(f, af, s);
}
extern "C" void
SwiftletApp__registerApps()
{
  SwiftletApp::registerApps();
}
