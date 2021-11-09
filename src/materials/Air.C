#include "Air.h"

registerMooseObject("bellApp", Air);

InputParameters
Air::validParams()
{
  auto params = ADMaterial::validParams();
  params.addRequiredParam<RealVectorValue>("velocity", "Wind speed vector");
  return params;
}

Air::Air(const InputParameters & params)
  : ADMaterial(params),
    _velocity(declareADProperty<RealVectorValue>("velocity"))
    {
    }


void
Air::computeQpProperties()
{
  _velocity[_qp] = getParam<RealVectorValue>("velocity");
}
