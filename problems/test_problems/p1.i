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
    value = 100
    point = '750 750'
  []
[]

[Kernels]
  [time_derivative]
    type = ADTimeDerivative
    variable = concentration
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
    velocity = '1 2 0'
  []
[]

[Problem]
  type = FEProblem
[]

[Executioner]
  type = Transient
  solve_type = NEWTON
  num_steps = 25
  petsc_options_iname = '-pc_type'
  petsc_options_value =  'hypre'
[]

[Outputs]
  exodus = true
[]
