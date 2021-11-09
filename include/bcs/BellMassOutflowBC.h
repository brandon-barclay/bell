#pragma once

#include "ADIntegratedBC.h"

class BellMassOutflowBC : public ADIntegratedBC
{
public:
  static InputParameters validParams();
  BellMassOutflowBC(const InputParameters & params);

protected:
  virtual ADReal computeQpResidual() override;

  const ADMaterialProperty<RealVectorValue> & _velocity;
};
