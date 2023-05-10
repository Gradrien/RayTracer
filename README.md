
![EPITECH](https://studyadv.s3.amazonaws.com/production/schools/covers/000/005/919/original/Enseigne_Epitech_2.png)


# RayTracer

Ray tracing is a powerful technique used to generate realistic digital images by simulating the inverse path of light. This project aims to develop a ray tracer program that can generate high-quality images based on a scene configuration file.

We had the following objectives:
* have multiple types of primitives (Spheres, Planes, Cylinders, ...)
* have multiple types of lights (Point, Directionnal, ...)
* have at least an output to a ppm file
* load the elements from a json configutation file, using [nlohmann-json3](https://github.com/nlohmann/json/) library

## Before continuing...

This project is an EPITECH Project. If you are an EPITECH student, move out the way !

Nothing to see here... I don't want to be involved to your -42.

![I'm watching you](https://media.tenor.com/ketvWma51gYAAAAd/john-cena-im-watching-you.gif)

If you're not, no worries! You're welcome here!

### Prerequisites

To use this project, you'll need a compiler that supports C++ 20.

This project can generate images in a [SFML](https://www.sfml-dev.org) window.

## Usage

### Building program

RayTracer is a B-OOP-400 EPITECH module project.
It is build with [CMake](https://cmake.org/).

You can use this program as it follows:
```bash
# Compile the project with flags required to close properly shared libraries, only available with g++

./compile.sh --gcc
```

Once the project is build, the `raytracer` executable is built at the root, and the plugins in the `plugins` directories:
```bash
.
├── plugins
│   ├── encoder
│   │   ├── ppmEncoder.so
│   │   └── sfmlEncoder.so
│   ├── lights
│   │   ├── ambient.so
│   │   ├── directional.so
│   │   └── point.so
│   │
│   ├── primitives
│   │   ├── cone.so
│   │   ├── cylinder.so
│   │   ├── plane.so
│   │   └── sphere.so
│   └── renderer
│       ├── baseRenderer.so
│       ├── fastRenderer.so
│       └── liveRenderer.so
│
└── raytracer
```

## Configuration file format

Here is the strucuture of the configuration file for the program

```json
{
  "global": {
    "encoder_name": Name (whithout .so extension) of the encoder located in the folder plugins/encoder,
    "renderer_name": Name (whithout .so extension) of the renderer located in the folder plugins/renderer,
    "output_file": Path of the generated image,
    "faster_render": OPTIONNAL name (whithout .so extension) of the renderer used to preview the generated image located in the folder plugins/renderer,
    "recursion_depth" : Value of the reflection reccursion (0 mean no reflection),
    "background_color": {
      "r": R value [0; 255],
      "g": G value [0; 255],
      "b": B value [0; 255]
    },
    "scene": OPTIONNAL Path of a scene to load in addtion with this one
  },
  "camera": {
    "resolution": {
      "width": Width in pixel of the generated image,
      "height": Height in pixel of the generated image
    },
    "origin": {
      "x": X value of the camera position,
      "y": Y value of the camera position,
      "z": Z value of the camera position
    },
    "rotation": {
      "x": Rotation angle of the camera on X axis,
      "y": Rotation angle of the camera on Y axis,
      "z": Rotation angle of the camera on Z axis
    },
    "screen": {
      "distance_with_camera": Distance beetween the screen and the camera (1 is a good value). The higher is the value, the higher is FOV,
      "height": Height of the screen in the raytracer 3D environnement (1 is a good value for a square image),
      "width": Width of the screen in the raytracer 3D environnement (1 is a good value for a square image)
    }
  },
  "primitives": {

    For each primitives type you can put an array with one element corrsponding to one primitive of the corresponding type.

    "sphere": [
      {
        "center": {
          "x": X value of the sphere position,
          "y": Y value of the sphere position,
          "z": Z value of the sphere position
        },
        "radius": Radius of the sphere,
        "color": {
           "r": R value [0; 255],
           "g": G value [0; 255],
           "b": B value [0; 255]
        },
        "reflection": Reflection index of the primitive [0; 1],
        "spec": Specularity index of the primitive can be -1 or > 0,
        "transparency": Transparency index of the primitive [0; 1]
      }
    ],
    "plane": [
      {
        "normal": {
          "x": X value of the plan normal vector,
          "y": Y value of the plan normal vector,
          "z": Z value of the plan normal vector
        },
        "translation": Translation of the plan following the normal vector,
        "color": {
           "r": R value [0; 255],
           "g": G value [0; 255],
           "b": B value [0; 255]
        },
        "rotation": {
          "x": Rotation of the plan on the X axis,
          "y": Rotation of the plan on the Y axis,
          "z": Rotation of the plan on the Z axis
        },
        "reflection": Reflection index of the primitive [0; 1],
        "spec": Specularity index of the primitive can be -1 or > 0,
        "transparency": Transparency index of the primitive [0; 1]
      }
    ],
    "cylinder" : [
      {
        "color": {
           "r": R value [0; 255],
           "g": G value [0; 255],
           "b": B value [0; 255]
        },
        "rotation": {
          "x": Rotation of the cylinder on the X axis,
          "y": Rotation of the cylinder on the Y axis,
          "z": Rotation of the cylinder on the Z axis
        },
        "crossing_point": {
          "x": X coordinate of a point crossed by the cylinder main axis,
          "y": Y coordinate of a point crossed by the cylinder main axis,
          "z": Z coordinate of a point crossed by the cylinder main axis
        },
        "radius": Radius of the cylinder,
        "reflection": Reflection index of the primitive [0; 1],
        "spec": Specularity index of the primitive can be -1 or > 0,
        "transparency": Transparency index of the primitive [0; 1]
      }
    ],
    "cone" : [
      {
        "color": {
           "r": R value [0; 255],
           "g": G value [0; 255],
           "b": B value [0; 255]
        },
        "rotation": {
          "x": Rotation of the cylinder on the X axis,
          "y": Rotation of the cylinder on the Y axis,
          "z": Rotation of the cylinder on the Z axis
        },
        "crossing_point": {
          "x": X coordinate of a point crossed by the cylinder main axis,
          "y": Y coordinate of a point crossed by the cylinder main axis,
          "z": Z coordinate of a point crossed by the cylinder main axis
        },
        "angle": Angle between the axis and the side of the cone,
        "reflection": Reflection index of the primitive [0; 1],
        "spec": Specularity index of the primitive can be -1 or > 0,
        "transparency": Transparency index of the primitive [0; 1]
      }
    ]
  },
  "lights": {
    "ambient": [
      {
        "color": {
          "r": R value [0; 255],
          "g": G value [0; 255],
          "b": B value [0; 255]
        },
        "intensity": [0; 1] where 0 mean no light and 1 mean full light power
      }
    ],
    "point": [
      {
        "color": {
          "r": R value [0; 255],
          "g": G value [0; 255],
          "b": B value [0; 255]
        },
        "x": X coordinate of the light position,
        "y": Y coordinate of the light position,
        "z": Z coordinate of the light position,
        "intensity": [0; 1] where 0 mean no light and 1 mean full light power
      }
    ],
    "directional": [
      {
        "color": {
          "r": R value [0; 255],
          "g": G value [0; 255],
          "b": B value [0; 255]
        },
        "x": X parameter of the light direction,
        "y": Y parameter of the light direction,
        "z": Z parameter of the light direction,
        "intensity": [0; 1] where 0 mean no light and 1 mean full light power
      }
    ]
  }
}
```

### Launch program

After building project, here is the output of the help:

```bash
$> ./raytracer -h
USAGE: ./raytracer <SCENE_FILE>
	SCENE_FILE: scene configuration
```

Launch the program:
```
$> ./raytracer scenes/duck.json
```

## Output examples

Here are some output from our RayTracer:

![](https://media.discordapp.net/attachments/1084823694095958087/1105776531994845245/image.png?width=686&height=683)

![](https://media.discordapp.net/attachments/1084823694095958087/1105863921862189127/Screenshot_20230510_182153.png?width=683&height=683)

![](https://media.discordapp.net/attachments/1084823694095958087/1105863922084495410/Screenshot_20230510_182215.png?width=683&height=683)

## Commit norm

The commits are normed thanks to a program made by [Adrien Ricou](https://github.com/Gradrien/Git-Shortcuts).

| Commit type       | Description        |
| --------- | --------------|
| [ADD] :rocket: | Deploying new code |
| [MODIFY] :sparkles: | Modifying code |
| [COD.STY] :zap: | Improving performance |
| [FIX] :bug: | Fixing a bug |
| [HANDLE] :sparkles: | Handling new features |
| [INCLUDE] :wrench: | Modifying user defined headers|
| [LIB] :wrench: | Modifying libraries files |
| [REMOVE] :fire: | Removing code or files |
| [UNIT.TESTS] :white_check_mark: | Added tests |
| [MERGE] :twisted_rightwards_arrows: | Merging branches |
| [DOCS] :memo: | Added documentation |
| [CI/CD] :green_heart: | CI/CD related push |
| [FIRST.PUSH] :tada: | First push hoorah |
| [HOTFIX] :ambulance: | Big problem, quick fix |
| [CODE.STRUCT] :art: | Code structure related push |
| [RESSOURCES] :truck: | New ressources added |
| [COMMENTS] :bulb: | Added commentaries |

**Emoji are available thanks to the Gitmoji tool

## Authors

* **Hippolyte David** - [HippolyteDavid](https://github.com/HippolyteDavid)
* **Elouan Savy-Camaret** - [ElouanSavy](https://github.com/ElouanSavy)
* **Léopold Sallan Gemard** - [Leo SG](https://github.com/Sosantoo)
* **Adrien Ricou** - [Gradrien](https://github.com/Gradrien)
