set terminal jpeg
set output "graph/grav_pot.jpg"
set yrange [-1e-8:0]
plot 'data/solarsystem.dat' using 1:3 ps 0.25 pt 7 lc rgb"#000000" notitle w lines