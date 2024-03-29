[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 200
  ny = 200
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
  [time_derivative]
    type = MassLumpedTimeDerivative
    variable = concentration
  []
  [diffusion]
    type = ConservativeAdvection
    variable = concentration
    upwinding_type = full
    velocity = '22 0 0'
  []
[]

[BCs]
  [all]
    type = BellMassOutflowBC
    boundary = 'top right'
    variable = concentration 
  []
[]

[Materials]
  [idk]
    type = Air
    velocity = '22 0 0'
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
  type = Transient
  num_steps = 70
  solve_type = NEWTON
  petsc_options_iname = '-pc_type'
  petsc_options_value =  'hypre'
  l_tol = 1E-14
[]

[Outputs]
  exodus = true
[]
