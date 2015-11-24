data segment
x db ?
y db ?
z db ?
data ends
code segment
assume cs:code,ds:data
start:
mov ax,3
mov x,ax
mov ax,2
mov y,ax

mov al,x
mov bl,y
xor ah,ah
add al,bl
aaa
mov z,ax

mov ax,z
mov dl,ah
add dl,30h
mov ah,2
int 21h
mov ax,z
mov dl,al
add dl,30h
mov ah,2
int 21h
mov ah,4ch
int 21h
code ends
end start
