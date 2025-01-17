
#Detect Platform
ifeq ($(OS), Windows_NT)
	OS_DEF = "WIN"
else
	OS_DEF = "LINUX"
endif

ifeq ($(OS_DEF), "WIN")
	#define win build vars
	CPPDEFS = -DWIN32 -DNOMINMAX
endif

ifeq ($(OS_DEF), "LINUX")
	#define linux build vars
endif


SRCPATH = ../src

CPPINCS = -I $(SRCPATH)/renderers/ \
          -I $(SRCPATH)//misc/ \
          -I $(SRCPATH)/scene/ \
          -I $(SRCPATH)/math/ \
          -I $(SRCPATH)/accelerators/ \
          -I ../lib/include

#CPPFLAGS = -Wall


RENDERSRC = $(SRCPATH)/renderers/RayTracer.cpp \
            $(SRCPATH)/renderers/Renderer.cpp \
            $(SRCPATH)/renderers/PhotonMapperCPU.cpp \
            $(SRCPATH)/renderers/PhotonMap.cpp \
            $(SRCPATH)/renderers/Photon.cpp \
            $(SRCPATH)/renderers/Sampler.cpp \
            $(SRCPATH)/renderers/Tonemap.cpp \
            $(SRCPATH)/renderers/OpenGLRenderer.cpp

MATHSRC =   $(SRCPATH)/math/Vector3.cpp \
            $(SRCPATH)/math/Point3.cpp \
            $(SRCPATH)/math/Affine4.cpp \
            $(SRCPATH)/math/Ray.cpp
          
ACCELSRC =  $(SRCPATH)/accelerators/BasicAS.cpp \
            $(SRCPATH)/accelerators/BVH.cpp \
            $(SRCPATH)/accelerators/IrradianceCache.cpp \
            $(SRCPATH)/accelerators/Kdtree.cpp \
            $(SRCPATH)/accelerators/UniformGrid.cpp

MISCSRC =   $(SRCPATH)/misc/Common.cpp \
            $(SRCPATH)/misc/Logfile.cpp \
            $(SRCPATH)/misc/Options.cpp \
            $(SRCPATH)/misc/Pixel.cpp \
            $(SRCPATH)/misc/SimpleProfiler.cpp \
            $(SRCPATH)/misc/Texture.cpp \
            $(SRCPATH)/misc/TextureMaker.cpp \
            $(SRCPATH)/misc/TextureManager.cpp \
            $(SRCPATH)/misc/Timer.cpp

SCENESRC =  $(SRCPATH)/scene/AABB.cpp \
            $(SRCPATH)/scene/Camera.cpp \
            $(SRCPATH)/scene/Color.cpp \
            $(SRCPATH)/scene/DynamicModel.cpp \
            $(SRCPATH)/scene/DynamicScene.cpp \
            $(SRCPATH)/scene/HitInfo.cpp \
            $(SRCPATH)/scene/IModel.cpp \
            $(SRCPATH)/scene/Material.cpp \
            $(SRCPATH)/scene/Material.cpp \
            $(SRCPATH)/scene/Model.cpp \
            $(SRCPATH)/scene/Objloader.cpp \
            $(SRCPATH)/scene/ObjModelloader.cpp \
            $(SRCPATH)/scene/PointLightPrim.cpp \
            $(SRCPATH)/scene/RectangleLight.cpp \
            $(SRCPATH)/scene/Scene.cpp \
            $(SRCPATH)/scene/SpherePrim.cpp \
            $(SRCPATH)/scene/Triangle.cpp \
            $(SRCPATH)/scene/TriangleLight.cpp \
            $(SRCPATH)/scene/TrianglePrim.cpp \
            $(SRCPATH)/scene/Vertex.cpp

CPPFILES = $(SRCPATH)/main.cpp \
           $(RENDERSRC) $(ACCELSRC) $(MATHSRC) $(MISCSRC) $(SCENESRC)

ifeq ($(OS_DEF), "WIN")
	CPPFILES += $(SRCPATH)/renderers/Shader.cpp
endif

ifeq ($(OS_DEF), "LINUX")
	LIBS = -l glut -l GLU
endif

ifeq ($(OS_DEF), "WIN")
	LIBPATH = -L lib/lib
	LIBS = -l cg -l cgGL -l glut32 -l OpenGL32 -l GLU32 -l corona
endif

default: link

compile:
	mkdir -p build
	cd ./build; g++ -c $(CPPFILES) $(CPPFLAGS) $(CPPINCS) $(CPPDEFS)

link: compile 
	g++ -o encore build/*.o $(LIBPATH) $(LIBS)

clean:
	rm -vf build/*.o ./encore   
