ARG VARIANT=ubuntu-24.04
FROM mcr.microsoft.com/devcontainers/base:${VARIANT}

ARG LLVM_VERSION=20

ENV DEBIAN_FRONTEND=noninteractive \
    CC=clang \
    CXX=clang++

SHELL ["/bin/bash", "-o", "pipefail", "-c"]

# 1) Install base build tools (rarely changes) - cached separately
RUN set -euxo pipefail \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
    ca-certificates \
    curl \
    gnupg \
    lsb-release \
    build-essential \
    git \
    cmake \
    ninja-build \
    && rm -rf /var/lib/apt/lists/*

# 2) Add LLVM APT key and repository (changes when LLVM_VERSION or base image changes)
RUN set -euxo pipefail \
    && install -d -m 0755 /etc/apt/keyrings \
    && curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key | gpg --dearmor -o /etc/apt/keyrings/llvm.gpg \
    && CODENAME=$(. /etc/os-release; echo "$VERSION_CODENAME") \
    && echo "deb [signed-by=/etc/apt/keyrings/llvm.gpg] http://apt.llvm.org/${CODENAME}/ llvm-toolchain-${CODENAME}-${LLVM_VERSION} main" > /etc/apt/sources.list.d/llvm.list

# 3) Install LLVM/Clang packages and configure alternatives (this will rerun when LLVM_VERSION changes)
RUN set -euxo pipefail \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
    clang-${LLVM_VERSION} \
    clangd-${LLVM_VERSION} \
    lld-${LLVM_VERSION} \
    llvm-${LLVM_VERSION} \
    llvm-${LLVM_VERSION}-dev \
    llvm-${LLVM_VERSION}-tools \
    && update-alternatives --install /usr/bin/clang clang /usr/bin/clang-${LLVM_VERSION} 100 \
    && update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-${LLVM_VERSION} 100 \
    && update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-${LLVM_VERSION} 100 \
    && rm -rf /var/lib/apt/lists/*
