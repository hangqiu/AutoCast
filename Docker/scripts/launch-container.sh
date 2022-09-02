#!/bin/bash
#
# AutoCast container launch script
#
# =================================================================================================
echo "CAVsec Agent Container"
echo ""
echo "Build: LOCAL_DEV"
echo ""

# =================================================================================================
# Preflight checks
# =================================================================================================

# Make sure NVIDIA-SMI works
nvidia-smi > /tmp/launch-nvidia-smi
if [ $? -ne 0 ];
then
    echo "Container error (2): NVIDIA GPU within the container not working properly. Confirm GPU is available and nvidia-container-toolkit is working?"
    exit 2
fi

# =================================================================================================
# Run supervisor in the foreground to keep the container up "forever"
# =================================================================================================
supervisord -n -c /etc/supervisord.conf