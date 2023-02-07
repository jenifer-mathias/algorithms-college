# Nome: Jenifer Mathias dos Santos
# TIA: 32092946

# if ( x == y) go to L2  
# a[1] = b - c;  
# b = a[2] + c;  
# c = b + c[3];  
# L2: a[4] = a[6] + a[5] 
# considere: a = $s0, b = $s1, c = $s2, x = $s3, y = $s4 

beq $s3, $s4, L2

lb $t3, 1($s0)
sub $s0, $s1, $s2

lb $t4, 2($s0)
add $s1, $s0, $s2

lb $t5, 3($s2)
add $s2, $s1, $s2

lb $t1, 6($s0)
lb $t2, 5($s0)
lb $t6, 4($s0)

L2: add $s0, $t1, $t2
