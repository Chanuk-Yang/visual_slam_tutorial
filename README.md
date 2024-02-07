# visual_slam_tutorial
## 코드의 목적
Stereo visual slam 구현을 위한 tutorial 모드.

## 코드 수정 범위
1. ROS 변경: dataset, visual_odometry, viewer(주석처리만 진행)
2. Frontend 개발: frontend, frame(원래 코드 그대로임), feature, mappoint
3. Backend 개발: backend, map

## 개발 환경
- Ubuntu 20.04
- ROS Noetic
- OpenCV 4 이상

## Dependency
- Sophus
- Eigen3
- G2O
- Pangolin
- GLog

## How to build & Execute
1. KITTI Dataset download
   https://www.cvlibs.net/datasets/kitti/eval_odometry.php
2. Dependency 설치
3. build 순서
   ```
   git clone https://github.com/Chanuk-Yang/visual_slam_tutorial.git
   cd visual_slam_tutorial
   mkdir build && cd build
   cmake ..
   make -j8
   ```
4. config 파일에서 directory 수정
5. 실행
   ```
   ./bin/run_kitti_stereo
   ```
   
   
## For docker user (권장)
```
git clone https://github.com/Chanuk-Yang/visual_slam_tutorial.git
docker pull chanuk/visual_slam_tutorial
docker run -td --privileged --net=host --ipc=host\
     --name="visual_slam"\
     -e "DISPLAY=$DISPLAY"\
     -e "QT_X11_NO_MITSHM=1"\
     -v "/tmp/.X11-unix:/tmp/.X11-unix:rw"\
     -e "XAUTHORITY=$XAUTH"\
     -e ROS_IP=127.0.0.1\
     --cap-add=SYS_PTRACE\
     -v `pwd`/dataset:/dataset\
     -v /etc/group:/etc/group:ro\
     -v `pwd`/visual_slam_tutorial:/visual_slam  --workdir /visual_slam\
     chanuk/visual_slam_tutorial bash
docker exec -it visual_slam bash
# docker 환경에서 실행
mkdir build && cd build
cmake ..
make -j8
```

## Reference
[1] https://github.com/gaoxiang12/slambook2

[2] https://www.cvlibs.net/datasets/kitti/eval_odometry.php
