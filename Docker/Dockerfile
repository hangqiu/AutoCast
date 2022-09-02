#
# AutoCast docker image
# Note: this is a WIP and is not ready yet!
#
# CUDA 11.0, Ubuntu 22.04 base image with nvidia-container-toolkit support
#
FROM docker.io/nvidia/cuda:11.0.3-cudnn8-devel-ubuntu20.04
RUN apt update

# Environment variables
ENV LANG en_US.UTF-8
ENV PYTHONIOENCODING=utf-8
ENV DEBIAN_FRONTEND=noninteractive

# Env vars for nvidia-container-runtime
ENV NVIDIA_VISIBLE_DEVICES all
ENV NVIDIA_DRIVER_CAPABILITIES graphics,utility,compute
ENV QT_X11_NO_MITSHM 1

# Make sure both the CUDA compiler and NVIDIA-SMI runs
# Note: if this fails, see:
#       https://stackoverflow.com/questions/59691207/docker-build-with-nvidia-runtime
RUN nvcc --version
RUN nvidia-smi

# Configure timezone so tzdata won't hang forever
ENV TZ=Etc/UTC
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Install base apt packages
RUN apt install -y mosquitto python3 python3-pip python3-dev python3-opencv python-is-python3 build-essential software-properties-common bash git zip unzip curl gnupg2 lsb-release wget mosquitto-clients can-utils libopenblas-dev curl nano vim iputils-ping net-tools traceroute tcpdump gcc g++ supervisor --no-install-recommends

# Update pip
RUN pip3 install --upgrade pip

# Base Python packages
RUN pip3 install numpy pygame pillow scipy paho-mqtt python-can pyserial ninja open3d

# CARLA 0.9.11
RUN apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 1AF1527DE64CB8D9
RUN add-apt-repository "deb [arch=amd64] http://dist.carla.org/carla $(lsb_release -sc) main"
RUN apt install -y carla-simulator=0.9.11 --no-install-recommends

# PyTorch 1.7.1 for CUDA 11.0
RUN pip3 install torch==1.7.1+cu110 torchvision==0.8.2+cu110 torchaudio==0.7.2 -f https://download.pytorch.org/whl/torch_stable.html

# PyTorch Geometrics
RUN pip3 install torch-scatter==2.0.7 torch-sparse==0.6.9 -f https://data.pyg.org/whl/torch-1.7.1+cu101.html

# Minkowski Engine
# (if something's going to fail, it's likely this step...)
RUN pip3 install -U MinkowskiEngine --install-option="--blas=openblas" -v --no-deps

# ======================================================================================
# Try not to edit anything above this line to avoid MinkowskiEngine compilation pains
# ======================================================================================

# AutoCast doesn't like default networkx
RUN apt purge -y python3-networkx

# Submodule things doesn't work in here (lack of SSH and a signed-in user, so let's do this for now)
RUN git clone https://github.com/hangqiu/AutoCast.git /opt/autocast
RUN git clone https://github.com/hangqiu/autocastsim /opt/autocast/AutoCastSim
RUN bash -c "cd /opt/autocast"
RUN bash -c "cd /opt/autocast && pip3 install -r requirements.txt"
RUN bash -c "cd /opt/autocast/AutoCastSim && pip3 install -r requirements.txt"
RUN chmod +x /opt/autocast/*.sh

# AutoCast environment variables
ENV AC_ROOT=/opt/autocast
ENV SIM_ROOT=/opt/autocast/AutoCastSim
ENV SCENARIO_RUNNER_ROOT=/opt/autocast/AutoCastSim/srunner
RUN bash -c "echo $PYTHONPATH"
ENV PYTHONPATH="${SCENARIO_RUNNER_ROOT}:${SIM_ROOT}"
RUN bash -c "echo $PYTHONPATH"

# Supervisor configuration
COPY configs/supervisord.conf /etc/supervisord.conf
COPY scripts/launch-container.sh /launch-container.sh
RUN chmod +x /launch-container.sh

# TODO: might need to expose CARLA RPC ports?

# What to execute?
CMD ["/bin/bash", "/launch-container.sh"]