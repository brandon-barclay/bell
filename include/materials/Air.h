#pragma once

#include "ADMaterial.h"

class Air : public ADMaterial
{
public:
  static InputParameters validParams();
  Air(const InputParameters & params);

protected:
  virtual void computeQpProperties() override;

  ADMaterialProperty<RealVectorValue> & _velocity;
};
