
cmake_minimum_required(VERSION 3.0.2)

project(LLVMCodeGen)


set( SOURCE 
AggressiveAntiDepBreaker.cpp
  AllocationOrder.cpp
  Analysis.cpp
  AtomicExpandPass.cpp
  BasicTargetTransformInfo.cpp
  BranchFolding.cpp
  BranchRelaxation.cpp
  BreakFalseDeps.cpp
  BuiltinGCs.cpp
  CalcSpillWeights.cpp
  CallingConvLower.cpp
  CFIInstrInserter.cpp
  CodeGen.cpp
  CodeGenPrepare.cpp
  CriticalAntiDepBreaker.cpp
  DeadMachineInstructionElim.cpp
  DetectDeadLanes.cpp
  DFAPacketizer.cpp
  DwarfEHPrepare.cpp
  EarlyIfConversion.cpp
  EdgeBundles.cpp
  ExecutionDomainFix.cpp
  ExpandISelPseudos.cpp
  ExpandMemCmp.cpp
  ExpandPostRAPseudos.cpp
  ExpandReductions.cpp
  FaultMaps.cpp
  FEntryInserter.cpp
  FuncletLayout.cpp
  GCMetadata.cpp
  GCMetadataPrinter.cpp
  GCRootLowering.cpp
  GCStrategy.cpp
  GlobalMerge.cpp
  IfConversion.cpp
  ImplicitNullChecks.cpp
  IndirectBrExpandPass.cpp
  InlineSpiller.cpp
  InterferenceCache.cpp
  InterleavedAccessPass.cpp
  InterleavedLoadCombinePass.cpp
  IntrinsicLowering.cpp
  LatencyPriorityQueue.cpp
  LazyMachineBlockFrequencyInfo.cpp
  LexicalScopes.cpp
  LiveDebugValues.cpp
  LiveDebugVariables.cpp
  LiveIntervals.cpp
  LiveInterval.cpp
  LiveIntervalUnion.cpp
  LivePhysRegs.cpp
  LiveRangeCalc.cpp
  LiveRangeEdit.cpp
  LiveRangeShrink.cpp
  LiveRegMatrix.cpp
  LiveRegUnits.cpp
  LiveStacks.cpp
  LiveVariables.cpp
  LLVMTargetMachine.cpp
  LocalStackSlotAllocation.cpp
  LoopTraversal.cpp
  LowLevelType.cpp
  LowerEmuTLS.cpp
  MachineBasicBlock.cpp
  MachineBlockFrequencyInfo.cpp
  MachineBlockPlacement.cpp
  MachineBranchProbabilityInfo.cpp
  MachineCombiner.cpp
  MachineCopyPropagation.cpp
  MachineCSE.cpp
  MachineDominanceFrontier.cpp
  MachineDominators.cpp
  MachineFrameInfo.cpp
  MachineFunction.cpp
  MachineFunctionPass.cpp
  MachineFunctionPrinterPass.cpp
  MachineInstrBundle.cpp
  MachineInstr.cpp
  MachineLICM.cpp
  MachineLoopInfo.cpp
  MachineModuleInfo.cpp
  MachineModuleInfoImpls.cpp
  MachineOperand.cpp
  MachineOptimizationRemarkEmitter.cpp
  MachineOutliner.cpp
  MachinePipeliner.cpp
  MachinePostDominators.cpp
  MachineRegionInfo.cpp
  MachineRegisterInfo.cpp
  MachineScheduler.cpp
  MachineSink.cpp
  MachineSSAUpdater.cpp
  MachineTraceMetrics.cpp
  MachineVerifier.cpp
  PatchableFunction.cpp
  MIRPrinter.cpp
  MIRPrintingPass.cpp
  MacroFusion.cpp
  OptimizePHIs.cpp
  ParallelCG.cpp
  PeepholeOptimizer.cpp
  PHIElimination.cpp
  PHIEliminationUtils.cpp
  PostRAHazardRecognizer.cpp
  PostRASchedulerList.cpp
  PreISelIntrinsicLowering.cpp
  ProcessImplicitDefs.cpp
  PrologEpilogInserter.cpp
  PseudoSourceValue.cpp
  ReachingDefAnalysis.cpp
  RegAllocBase.cpp
  RegAllocBasic.cpp
  RegAllocFast.cpp
  RegAllocGreedy.cpp
  RegAllocPBQP.cpp
  RegisterClassInfo.cpp
  RegisterCoalescer.cpp
  RegisterPressure.cpp
  RegisterScavenging.cpp
  RenameIndependentSubregs.cpp
  MIRCanonicalizerPass.cpp
  RegisterUsageInfo.cpp
  RegUsageInfoCollector.cpp
  RegUsageInfoPropagate.cpp
  ResetMachineFunctionPass.cpp
  SafeStack.cpp
  SafeStackColoring.cpp
  SafeStackLayout.cpp
  ScalarizeMaskedMemIntrin.cpp
  ScheduleDAG.cpp
  ScheduleDAGInstrs.cpp
  ScheduleDAGPrinter.cpp
  ScoreboardHazardRecognizer.cpp
  ShadowStackGCLowering.cpp
  ShrinkWrap.cpp
  SjLjEHPrepare.cpp
  SlotIndexes.cpp
  SpillPlacement.cpp
  SplitKit.cpp
  StackColoring.cpp
  StackMapLivenessAnalysis.cpp
  StackMaps.cpp
  StackProtector.cpp
  StackSlotColoring.cpp
  TailDuplication.cpp
  TailDuplicator.cpp
  TargetFrameLoweringImpl.cpp
  TargetInstrInfo.cpp
  TargetLoweringBase.cpp
  TargetLoweringObjectFileImpl.cpp
  TargetOptionsImpl.cpp
  TargetPassConfig.cpp
  TargetRegisterInfo.cpp
  TargetSchedule.cpp
  TargetSubtargetInfo.cpp
  TwoAddressInstructionPass.cpp
  UnreachableBlockElim.cpp
  ValueTypes.cpp
  VirtRegMap.cpp
  WasmEHPrepare.cpp
  WinEHPrepare.cpp
  XRayInstrumentation.cpp
)




#set win32/win64
if(MSVC)
if(CMAKE_CL_64)
add_definitions(-DWIN64)
else()
add_definitions(-DWIN32)
endif()
endif()

#include
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/CodeGen)
include_directories(${CMAKE_SOURCE_DIR}/include/CodeGen/PBQP)


add_library(${PROJECT_NAME} STATIC ${SOURCE} )

 #X86 backend
add_subdirectory(GlobalISel)
set_target_properties(LLVMGlobalISel PROPERTIES FOLDER "CodeGen")

add_subdirectory(SelectionDAG)
set_target_properties(LLVMSelectionDAG PROPERTIES FOLDER "CodeGen")

add_subdirectory(MIRParser)
set_target_properties(LLVMMIRParser PROPERTIES FOLDER "CodeGen")

add_subdirectory(AsmPrinter)
set_target_properties(LLVMAsmPrinter PROPERTIES FOLDER "CodeGen")


target_link_libraries(${PROJECT_NAME} LLVMGlobalISel)
target_link_libraries(${PROJECT_NAME} LLVMSelectionDAG)
target_link_libraries(${PROJECT_NAME} LLVMMIRParser)
target_link_libraries(${PROJECT_NAME} LLVMAsmPrinter)
