/** @file visualizerIrrlicht.h
*
* Visualizer interface
*/


#ifndef _VISUALIZERIRRLICHT_H_
#define _VISUALIZERIRRLICHT_H_


#include "irrlicht.h"
#include "../defs/defs.h"
#include "../../3rdParty/tinyXML/tinyxml2.h"
#include <iostream>
#include <string>
#include <vector>
#include "visualizer.h"
#include "../include/visualization/myeventreceiver.h"


namespace controller {
    Visualizer* createVisualizerIrrlicht(const std::string _name, int width, int height, irr::f32 axisBoxSize);
    Visualizer* createVisualizerIrrlicht(std::string configFilename, const std::string _name, int width, int height, irr::f32 axisBoxSize);
};

using namespace controller;


    /// VisualizerGL interface
    class VisualizerIrrlicht : public Visualizer {
    public:


        /// Pointer
        typedef std::unique_ptr<VisualizerIrrlicht> Ptr;

        /// overloaded constructor
        VisualizerIrrlicht(const std::string _name, int width, int height, irr::f32 axisBoxSize);

        VisualizerIrrlicht(std::string configFilename, const std::string _name, int width, int height, irr::f32 axisBoxSize);

        /** Name of the Robot
        * @param string& name
        */
        const std::string& getName() const { return name; }

        /** Draws a robot
        * @param Mat34& robotPose
        * @param vector<float_type> configuration
        */
        void drawRobot(const Mat34& robotPose, std::vector<float_type> configuration);

        void setDebugMode(bool enable);

        /// Virtual descrutor
        ~VisualizerIrrlicht() {}

    private:
        //DB przypisanie wartosci w konstruktorze
        bool debug = false;

        MyEventReceiver receiver;
        IrrlichtDevice *device;

        irr::video::IVideoDriver* video;
        irr::scene::IMeshBuffer* coxaMeshBuffer;
        irr::scene::IMeshBuffer* vitulusMeshBuffer;
        irr::scene::IMeshBuffer* femurMeshBuffer;
        irr::scene::IMeshBuffer* korpusMeshBuffer;
        irr::video::SMaterial videoMaterial;
        irr::scene::ICameraSceneNode* camera;
        irr::scene::ISceneManager * manager;



        //DB prosze tutaj tylko zadeklarowac stala, a inicjalizowac w konstruktorze za pomoca listy
        //DB nienajlepsza nazwa zmiennej: lepiej np. boxSize;
        const irr::f32 axisBoxSize;

        /** Draws a signle leg
        * @param int legIndex
        * @param Vec3 position
        * @param Vec3 rotation
        */
        void drawLeg(int legIndex,  irr::core::vector3d<irr::f32> position, irr::core::vector3d<irr::f32> radians, std::vector<float_type> configuration);



        /** Rotates and transforms the space
        * @param vector3d<f32> radians
        * @param vector3d<f32> position
        */
        void ourTransform(irr::core::vector3d<irr::f32> radians, irr::core::vector3d<irr::f32> position);

        /** Tranforms Mat34 to Irrlicht
        * @param const Mat34& robotPose robotPose
        */
        void mat34ToIrrlichtTransform(const Mat34& robotPose);


        /** Rotates and transforms the space
        * @param f32 xRad
        * @param f32 yRad
        * @param f32 zRad
        * @param f32 xTrans
        * @param f32 yTrans
        * @param f32 zTrans
        */
        void ourTransform(irr::f32 xRad, irr::f32 yRad, irr::f32 zRad, irr::f32 xTrans, irr::f32 yTrans, irr::f32 zTrans);


        /** Draws axis in debug mode
        */
        void drawAxis();

        /** Draws robot body
        * @param vector3d<f32> radians
        * @param vector3d<f32> position
        */
        void drawBody(irr::core::vector3d<irr::f32> position, irr::core::vector3d<irr::f32> radians);

        /** Initializes Irrlicht engine. Loads meshes and materials.
        */
        int initialize(int width, int height);

        /** Sets camera target
         *  @param irr::core::vector3df target
        */
        void setCameraTarget(irr::core::vector3df target);

        /** Sets camera position
         *  @param irr::core::vector3df target
        */
        void setCameraPosition(irr::core::vector3df position);


    };




#endif // _VISUALIZERIRRLICHT_H_
