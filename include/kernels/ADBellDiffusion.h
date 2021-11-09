#pragma once 

#include "ADDiffusion.h"

class ADBellDiffusion : public ADDiffusion 
{
    public:
        static InputParameters validParams();
        ADBellDiffusion(const InputParameters & params);

    protected:
        virtual ADRealVectorValue precomputeQpResidual() override;

        const ADMaterialProperty<Real> & _diffusivity;
};