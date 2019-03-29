Processor Architecture
======================

Emilio Campos

The block diagram for the Raspberry Pi 3's processor:

.. image:: https://static.docs.arm.com/ddi0344/k/graphics/cortex_a8_block.svg
  
**Instruction Fetch Unit** 

The instruction fetch unit predicts the instruction stream, fetches instructions from the L1 instruction cache, and places the fetched instructions into a buffer for consumption by the decode pipeline. The instruction fetch unit also includes the L1 instruction cache.

**Instruction Decode Unit**

The instruction decode unit decodes and sequences all ARM and Thumb-2 instructions including debug control coprocessor, CP14, instructions and system control coprocessor, CP15, instructions.
The instruction decode unit handles the sequencing of:

exceptions

debug events

reset initialization

Memory Built-In Self Test (MBIST)

wait-for-interrupt

other unusual events.

**Instruction Execute Unit**

The instruction execute unit consists of two symmetric Arithmetic Logical Unit (ALU) pipelines, an address generator for load and store instructions, and the multiply pipeline. The execute pipelines also perform register write back.

The instruction execute unit:

executes all integer ALU and multiply operations including flag generation

generates the virtual addresses for loads and stores and the base write-back value, when required

supplies formatted data for stores and also forwards data and flags

processes branches and other changes of instruction stream and evaluates instruction condition codes.

**Load/Store Unit**

The load/store unit encompasses the entire L1 data side memory system and the integer load/store pipeline. This includes:

the L1 data cache

the data side TLB

the integer store buffer

the NEON store buffer

the integer load data alignment and formatting

the integer store data alignment and formatting.

The pipeline accepts one load or store per cycle that can be present in either pipeline 0 or pipeline 1. This gives the processor flexibility when scheduling load and store instructions.

**L2 Cache Unit**

The L2 cache unit includes the L2 cache and the Buffer Interface Unit (BIU). It services L1 cache misses from both the instruction fetch unit and the load/store unit.

**NEON Unit**

The NEON unit includes the full 10-stage NEON pipeline that decodes and executes the Advanced SIMD media instruction set. The NEON unit includes:

the NEON instruction queue

the NEON load data queue

two pipelines of NEON decode logic

three execution pipelines for Advanced SIMD integer instructions

two execution pipelines for Advanced SIMD floating-point instructions

one execution pipeline for Advanced SIMD and VFP load/store instructions

the VFP engine for full execution of the VFPv3 data-processing instruction set.

**ETM unit**

The ETM unit is a non-intrusive trace macrocell that filters and compresses an instruction and data trace for use in system debugging and system profiling.

