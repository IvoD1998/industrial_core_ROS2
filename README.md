# Industrial Core
[ROS-Industrial][] core communications packages. See the [ROS wiki][] page for more information.


## Contents
This repository is a port for ROS2 

Older releases may be found in the old ROS-Industrial [subversion repository][].


## Status

The packages in this repository are *community supported*.
This means they do not get support from an OEM, nor from the ROS-Industrial consortia directly (see also the `support level` badge at the top of this page).

Maintenance and development is on a best-effort basis and depends on volunteers.

## Building

### Building the packages

The following instructions assume that a workspace has been created at `$HOME/colcon_ws` and that the *source space* is at `$HOME/colcon_ws/src`. Update paths appropriately if they are different on the build machine.

These instructions build the `humble` branch on a ROS2 humble system:

```bash
# change to the root of the colcon workspace
$ cd $HOME/colcon_ws

# retrieve the latest development version of industrial_core_ROS2. 
$ git clone -b humble git@github.com:IvoD1998/industrial_core_ROS2.git src/industrial_core_ROS2

# check build dependencies. Note: this may install additional packages,
# depending on the software installed on the machine
$ rosdep update
$ rosdep install --from-paths src/ --ignore-src

# build the workspace
$ colcon build
```

### Activating the workspace

Finally, activate the workspace to get access to the packages just built:

```bash
$ source $HOME/colcon_ws/install/setup.bash
```
### Note 
the velocity scaling factor does not seem to work when using the MoveIt! gui in RViz; The robot moves very slowly. When using the move_group C++ interface, it works as expected



