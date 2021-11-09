#include "ADBellDiffusion.h"

registerMooseObject("bellApp", ADBellDiffusion);

InputParameters
ADBellDiffusion::validParams()
{
    auto params = ADDiffusion::validParams();
    params.addClassDescription("ADDiffusion plus the diffusivity material property.");
    params.addRequiredParam<Real>("diffusivity", "The diffusivity of the material in air");
    return params;
}

ADBellDiffusion::ADBellDiffusion(const InputParameters & params)
    : ADDiffusion(params),
      _diffusivity(getADMaterialProperty<Real>("diffusivity"))
      {

      }

ADRealVectorValue
ADBellDiffusion::precomputeQpResidual()
{
    return _diffusivity[_qp] * ADDiffusion::precomputeQpResidual();
}

