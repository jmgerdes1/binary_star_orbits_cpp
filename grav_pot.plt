set terminal jpeg
set output "graph/grav_pot.jpg"
set xlabel "x"
set ylabel "y"
set zrange [-1e29:0]
#set pm3d at b
splot "data/solarsystem.dat" u 1:2:3 notitle linecolor palette w pm3d