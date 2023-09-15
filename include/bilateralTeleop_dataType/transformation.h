#pragma once
#include <SpaceVecAlg/SpaceVecAlg>
#include <eigen3/Eigen/Dense>
#include <vector>
#include <map>
#include "type.h"
#include "boost_serialization_eigen.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>

namespace bilateralTeleop
{
class transformation
{
    public:
    transformation()
    {
        transformation(bilateralTeleop::Name::A,bilateralTeleop::Type::Human);
    }
    transformation(const bilateralTeleop::Name & n,const bilateralTeleop::Type & t)
    {
        name_ = n;
        type_ = t;
        for (int partInt = Limbs::Head ; partInt != Limbs::RightArm ; partInt++) {
            Limbs part = static_cast<Limbs>(partInt);
            transformations_E_[part] = Eigen::Matrix3d::Identity();
            transformations_T_[part] = Eigen::Vector3d::Zero();
        }
    }
    void add(Limbs part, const sva::PTransformd & transfo)
    {
        transformations_E_[part] = transfo.rotation();
        transformations_T_[part] = transfo.translation();

    }
    sva::PTransformd get(Limbs part)
    {
        return sva::PTransformd(transformations_E_[part],transformations_T_[part]);
    }

    bilateralTeleop::Name name()
    {
        return name_;
    }
    void name(Name name)
    {
        name_ = name;
    }
    bilateralTeleop::Type type()
    {
        return type_;
    }

    private:
    std::map<bilateralTeleop::Limbs, Eigen::Matrix3d> transformations_E_;
    std::map<bilateralTeleop::Limbs, Eigen::Vector3d> transformations_T_;
    bilateralTeleop::Name name_;
    bilateralTeleop::Type type_;
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar & transformations_E_;
        ar & transformations_T_;
        ar & name_;
        ar & type_;
    }
};  

}