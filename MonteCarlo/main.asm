.data 
_1 dq 1.0
_4 dq 4.0

.code 
TrimiteArray proc
mov RAX,8
MUL RDX
SUB RAX,8
ADD RAX,RCX
XOR R10,R10
XOR R11,R11

HeadLoop: movsd xmm1, real8 ptr [RCX]
ADD RCX,8
mulsd xmm1,xmm1

movsd xmm2, real8 ptr [RAX]
sub RAX,8
mulsd xmm2,xmm2

addsd xmm1,xmm2

movsd xmm2, [_1]
comisd xmm1,xmm2
jc circle
ADD R11,1
jmp compar
circle: ADD R10,1
ADD R11,1
compar: cmp RCX,RAX
jb HeadLoop

movq xmm0,R10
movq xmm1,R11
mulsd xmm0,[_4]
divsd xmm0,xmm1
ret
TrimiteArray endp

end