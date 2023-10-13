set terminal jpeg
set output "graph/grav_pot.jpg"
set xlabel "x"
set ylabel "y"
set zrange [-1e29:0]
IGNORE_BELOW=-1e28
#set hidden3d
#set pm3d at b
#set dgrid3d 50,50 qnorm 3
splot "data/solarsystem.dat" u 1:2:3 notitle linecolor palette w pm3d