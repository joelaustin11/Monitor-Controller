@ Fast assembly for volume data for PGA2310 volume control ic
@ Program takes left and right cahnnel 8 bits values and shifts them into
@ 16 bit word and outputs on address 0x20000008
@
@ R1 = LEFT CHANNNEL address
@ R2 = RIGHT CHANNEL address
@ R3 = temp register for left channel value
@ R4 = temp register for right channel
@ R5 = final value register
@ R6 = output address 


#define CHANNEL_ADDR_BASE 0x20


.thumb_func @ SDK uses BLX

.global spi_buffer 

spi_buffer:     MOV R1, #CHANNEL_ADDR_BASE @ Move 0x20 into r1
                LSL R1, R1, #24 @ becomes 0x20000000 
                @ R1 is LEFT CHANNEL address
                ADD R2, R1, #0x4 @ R2 becomes 0x20000004
                @ R2 is RIGHT CHANNEL address
                MOV R6, #CHANNEL_ADDR_BASE @ Move base into output address register
                ADD R6, R6, #0x8 @ R6 becomes 0x20000008 
                @ R6 is OUTPUT address

                @ Shifting 
                LDR R3, [R1] @ load LEFT CHANNEL into R3 
                LDR R4, [R2] @ load RIGHT CHANNEL into R4 
                LSR R5, R3, #8 @ Shift LEFT CHANNEL right 8-bits adn put in R5 
                ADD R5, R4 @ add left channel to right channel to make 16 bit word 

                @ Output
                STRH R5, [R6] @ store halfbit word (16-bits) in 0x20000008 

                BX LR 



            