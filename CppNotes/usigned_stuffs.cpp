#include<iostream>
#include<cstdint>


int main(){
	// the following two are same thing
	unsigned u;
	unsigned int ui;
	
	// need #include<cstdint>
	uint16_t u16;	// 16bit	2B
	uint32_t u32;	// 32bit	4B	
	
	// need #include<cstddef>(specifically handles "size" and "index") or  #include<iostream>
	size_t s;	// 64bit	8B
}
