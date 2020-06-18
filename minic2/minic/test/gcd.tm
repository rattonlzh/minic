* TINY Compilation to TM Code
* File: ../test/gcd.tm
* Standard prelude:
  0:     LD  5,0(0) 	load gp with maxaddress
  1:    LDA  6,0(5) 	copy gp to mp
  2:     ST  0,0(0) 	clear location 0
* End of standard prelude.
* -> Function (gcd)
  4:     ST  1,-2(5) 	func: store the location of func. entry
* func: unconditional jump to next declaration belongs here
* func: function body starts here
  3:    LDC  1,6(0) 	func: load function location
  6:     ST  0,-1(6) 	func: store return address
* -> param
* u
* <- param
* -> param
* v
* <- param
* -> compound
* -> if
* -> Op
* -> Id (v)
  7:    LDC  0,-3(0) 	id: load varOffset
  8:    ADD  0,6,0 	id: calculate the address
  9:     LD  0,0(0) 	load id value
* <- Id
 10:     ST  0,-4(6) 	op: push left
* -> Const
 11:    LDC  0,0(0) 	load const
* <- Const
 12:     LD  1,-4(6) 	op: load left
 13:    SUB  0,1,0 	op ==
 14:    JEQ  0,2(7) 	br if true
 15:    LDC  0,0(0) 	false case
 16:    LDA  7,1(7) 	unconditional jmp
 17:    LDC  0,1(0) 	true case
* <- Op
* if: jump to else belongs here
* -> return
* -> Id (u)
 19:    LDC  0,-2(0) 	id: load varOffset
 20:    ADD  0,6,0 	id: calculate the address
 21:     LD  0,0(0) 	load id value
* <- Id
 22:     LD  7,-1(6) 	return: to caller
* <- return
* if: jump to end belongs here
 18:    JEQ  0,5(7) 	if: jmp to else
* -> return
* -> Call
* -> Id (v)
 24:    LDC  0,-3(0) 	id: load varOffset
 25:    ADD  0,6,0 	id: calculate the address
 26:     LD  0,0(0) 	load id value
* <- Id
 27:     ST  0,-6(6) 	call: push argument
* -> Op
* -> Id (u)
 28:    LDC  0,-2(0) 	id: load varOffset
 29:    ADD  0,6,0 	id: calculate the address
 30:     LD  0,0(0) 	load id value
* <- Id
 31:     ST  0,-4(6) 	op: push left
* -> Op
* -> Op
* -> Id (u)
 32:    LDC  0,-2(0) 	id: load varOffset
 33:    ADD  0,6,0 	id: calculate the address
 34:     LD  0,0(0) 	load id value
* <- Id
 35:     ST  0,-5(6) 	op: push left
* -> Id (v)
 36:    LDC  0,-3(0) 	id: load varOffset
 37:    ADD  0,6,0 	id: calculate the address
 38:     LD  0,0(0) 	load id value
* <- Id
 39:     LD  1,-5(6) 	op: load left
 40:    DIV  0,1,0 	op /
* <- Op
 41:     ST  0,-5(6) 	op: push left
* -> Id (v)
 42:    LDC  0,-3(0) 	id: load varOffset
 43:    ADD  0,6,0 	id: calculate the address
 44:     LD  0,0(0) 	load id value
* <- Id
 45:     LD  1,-5(6) 	op: load left
 46:    MUL  0,1,0 	op *
* <- Op
 47:     LD  1,-4(6) 	op: load left
 48:    SUB  0,1,0 	op -
* <- Op
 49:     ST  0,-7(6) 	call: push argument
 50:     ST  6,-4(6) 	call: store current mp
 51:    LDA  6,-4(6) 	call: push new frame
 52:    LDA  0,1(7) 	call: save return in ac
 53:     LD  7,-2(5) 	call: relative jump to function entry
 54:     LD  6,0(6) 	call: pop current frame
* <- Call
 55:     LD  7,-1(6) 	return: to caller
* <- return
 23:    LDA  7,32(7) 	jmp to end
* <- if
* <- compound
 56:     LD  7,-1(6) 	func: load pc with return address
  5:    LDA  7,51(7) 	func: unconditional jump to next declaration
* -> Function (gcd)
* -> Function (main)
 58:     ST  1,-3(5) 	func: store the location of func. entry
* func: unconditional jump to next declaration belongs here
* func: function body starts here
 57:    LDC  1,60(0) 	func: load function location
 60:     ST  0,-1(6) 	func: store return address
* -> compound
* -> assign
* -> Id (x)
 61:    LDC  0,-2(0) 	id: load varOffset
 62:    ADD  0,6,0 	id: calculate the address
 63:    LDA  0,0(0) 	load id address
* <- Id
 64:     ST  0,-4(6) 	assign: push left (address)
* -> Call
 65:     IN  0,0,0 	read integer value
* <- Call
 66:     LD  1,-4(6) 	assign: load left (address)
 67:     ST  0,0(1) 	assign: store value
* <- assign
* -> assign
* -> Id (y)
 68:    LDC  0,-3(0) 	id: load varOffset
 69:    ADD  0,6,0 	id: calculate the address
 70:    LDA  0,0(0) 	load id address
* <- Id
 71:     ST  0,-4(6) 	assign: push left (address)
* -> Call
 72:     IN  0,0,0 	read integer value
* <- Call
 73:     LD  1,-4(6) 	assign: load left (address)
 74:     ST  0,0(1) 	assign: store value
* <- assign
* -> iter.
* while: jump after body comes back here
* -> Const
 75:    LDC  0,1(0) 	load const
* <- Const
* while: jump to end belongs here
* -> compound
* <- compound
 77:    LDA  7,-3(7) 	while: jmp back to test
 76:    JEQ  0,1(7) 	while: jmp to end
* <- iter.
* -> Call
* -> Call
* -> Id (x)
 78:    LDC  0,-2(0) 	id: load varOffset
 79:    ADD  0,6,0 	id: calculate the address
 80:     LD  0,0(0) 	load id value
* <- Id
 81:     ST  0,-6(6) 	call: push argument
* -> Id (y)
 82:    LDC  0,-3(0) 	id: load varOffset
 83:    ADD  0,6,0 	id: calculate the address
 84:     LD  0,0(0) 	load id value
* <- Id
 85:     ST  0,-7(6) 	call: push argument
 86:     ST  6,-4(6) 	call: store current mp
 87:    LDA  6,-4(6) 	call: push new frame
 88:    LDA  0,1(7) 	call: save return in ac
 89:     LD  7,-2(5) 	call: relative jump to function entry
 90:     LD  6,0(6) 	call: pop current frame
* <- Call
 91:     ST  0,-6(6) 	call: push argument
 92:     LD  0,-6(6) 	load arg to ac
 93:    OUT  0,0,0 	write ac
* <- Call
* <- compound
 94:     LD  7,-1(6) 	func: load pc with return address
 59:    LDA  7,35(7) 	func: unconditional jump to next declaration
* -> Function (main)
 95:    LDC  0,-2(0) 	init: load globalOffset
 96:    ADD  6,6,0 	init: initialize mp with globalOffset
* -> Call
 97:     ST  6,0(6) 	call: store current mp
 98:    LDA  6,0(6) 	call: push new frame
 99:    LDA  0,1(7) 	call: save return in ac
100:    LDC  7,60(0) 	call: unconditional jump to main() entry
101:     LD  6,0(6) 	call: pop current frame
* <- Call
* End of execution.
102:   HALT  0,0,0 	
