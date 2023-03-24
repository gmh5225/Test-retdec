#add_subdirectory(DWARF)
#add_subdirectory(MSF)

add_subdirectory(CodeView)
set_target_properties(LLVMDebugInfoCodeView PROPERTIES FOLDER "CodeView")

#add_subdirectory(PDB)
#add_subdirectory(Symbolize)
