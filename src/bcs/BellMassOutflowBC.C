#include "BellMassOutflowBC.h"

registerMooseObject("bellApp", BellMassOutflowBC);

InputParameters
BellMassOutflowBC::validParams()
{
  InputParameters params = ADIntegratedBC::validParams();
  params.addClassDescription("Material outflow boundary condition implemented from ADIntegratedBC");
  return params;
}

BellMassOutflowBC::BellMassOutflowBC(const InputParameters & params)
  : ADIntegratedBC(params),
    _velocity(getADMaterialProperty<RealVectorValue>("velocity"))
    {
    }

ADReal
BellMassOutflowBC::computeQpResidual()
{
  if (_velocity[_qp] * _normals[_qp] > 0)
  {
    return - _test[_i][_qp] * _u[_qp] * _velocity[_qp] * _normals[_qp];
  }
  else
  {
    return 0;
  }
}
