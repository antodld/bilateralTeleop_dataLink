#pragma once
#include <iostream>
namespace bilateralTeleop
{
enum Limbs
{
    Head,
    Pelvis,
    LeftHand,
    LeftForearm,
    LeftArm,
    RightHand,
    RightForearm,
    RightArm
};

inline Limbs str2Limb(const std::string & name)
{

    if(name == "LeftHand"){ return Limbs::LeftHand;}
    if(name == "RightHand"){ return Limbs::RightHand;}
    if(name == "LeftArm"){ return Limbs::LeftArm;}
    if(name == "RightArm"){ return Limbs::RightArm;}
    if(name == "LeftForearm"){ return Limbs::LeftForearm;}
    if(name == "RightForearm"){ return Limbs::RightForearm;}
    if(name == "Pelvis"){ return Limbs::Pelvis;}
    if(name == "Head"){ return Limbs::Head;}

    std::cout << "Link not recognized : Available links :\n" << "LeftHand\nRightHand\nLeftArm\nRightArm\nLeftForearm\nRightForearm\nPelvis\nHead" << std::endl;
    return Limbs::LeftHand;

}

enum Type
{
    Human,
    Robot
};
enum Name
{
    A,
    B
};
}