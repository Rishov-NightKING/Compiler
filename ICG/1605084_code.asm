.MODEL SMALL
.STACK 100H
.DATA 
main_return dw ?
t0 dw ?
t1 dw ?
a2 dw 100 dup(?)
.CODE
main PROC
MOV AX, @DATA
MOV DS, AX
MOV t0, 5
MOV BX, t0
ADD BX, BX
MOV t1, 10
MOV AX, t1
MOV a2, AX
LReturnmain:
MOV AH, 4CH
INT 21H
OUTDEC PROC
PUSH AX
PUSH BX
PUSH CX
PUSH DX
CMP AX, 0
JGE BEGIN
PUSH AX
MOV DL, '-'
MOV AH, 2
INT 21H
POP AX
NEG AX

BEGIN:
XOR CX, CX
MOV BX, 10

REPEATATION:
XOR DX, DX
DIV BX
PUSH DX
INC CX
OR AX, AX
JNE REPEATATION
MOV AH, 2

LOOP_PRINT:
POP DX
ADD DL, 30H
INT 21H
LOOP LOOP_PRINT

MOV AH, 2
MOV DL, 10
INT 21H

MOV DL, 13
INT 21H

POP DX
POP CX
POP BX
POP AX
RET
OUTDEC ENDP
END MAIN


