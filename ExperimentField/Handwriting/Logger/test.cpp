#include "logger.cpp"

int main(){
    Shovy::Logger logger("logger");
    logger.info("nothing...");
    logger.warning("gogog");
    logger.error("fuc");
}