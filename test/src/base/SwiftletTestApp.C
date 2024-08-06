//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "SwiftletTestApp.h"
#include "SwiftletApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
SwiftletTestApp::validParams()
{
  InputParameters params = SwiftletApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

SwiftletTestApp::SwiftletTestApp(InputParameters parameters) : MooseApp(parameters)
{
  SwiftletTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

SwiftletTestApp::~SwiftletTestApp() {}

void
SwiftletTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  SwiftletApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"SwiftletTestApp"});
    Registry::registerActionsTo(af, {"SwiftletTestApp"});
  }
}

void
SwiftletTestApp::registerApps()
{
  registerApp(SwiftletApp);
  registerApp(SwiftletTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
SwiftletTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  SwiftletTestApp::registerAll(f, af, s);
}
extern "C" void
SwiftletTestApp__registerApps()
{
  SwiftletTestApp::registerApps();
}
