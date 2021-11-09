[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 100
  xmax = 1500
  ymax = 1500
[]

[Variables]
  [concentration]
    initial_condition = 0
  []
[]

[DiracKernels]
  [emission_source]
    type = ConstantPointSource
    variable = concentration
    value = 10
    point = '750 750'
  []
[]

[Kernels]
  #[time_derivative]
  #  type = ADTimeDerivative
  #  variable = concentration
  #[]
  [diffusion]
    type = ADBellDiffusion
    variable = concentration
    diffusivity = 1
  []
[]

[BCs]
  [all]
    type = BellMassOutflowBC
    variable = concentration
    boundary = 'left right top bottom'
  []
[]

[Materials]
  [idk]
    type = Air
    velocity = '0.000000001 0.000000001 0'
  []
  [radioactive_material]
    type = ADGenericConstantMaterial
    prop_names = 'diffusivity'
    prop_values = '0.75'
  []
[]

[Problem]
  type = FEProblem
[]

[Executioner]
  type = Steady
  solve_type = NEWTON
  petsc_options_iname = '-pc_type'
  petsc_options_value =  'hypre'
[]

[Outputs]
  exodus = true
[]
