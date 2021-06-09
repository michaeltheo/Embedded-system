import math

"""
  Fclock: MHz
  inner_divider: 1/4
  prog_divider: 1/2 | 1/4 | 1/8 | 1/16 | 1/32 | 1/64 | 1/128 | 1/256
  goal: μs
"""
def get_start_timer(Fclock,inner_divider,prog_divider,goal):
  F_inner_divider_output = Fclock*inner_divider
  T = 1/F_inner_divider_output
  T = round(T,5)
  
  F_prog_divider_output = pow(F_inner_divider_output * prog_divider,-1)
  F_prog_divider_output = round(F_prog_divider_output,5)

  y = 65536 - (goal/F_prog_divider_output)
  y = round(y)

  print(f"F_prog_divider_output = {F_prog_divider_output} μs")
  print(f"T = {T} μs")
  print("Timer input value: ",y)


# get_start_timer(48,1/4,1/256,1000000) #1 second