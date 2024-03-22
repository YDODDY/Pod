// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NierPod/BossController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBossController() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	NIERPOD_API UClass* Z_Construct_UClass_ABossController();
	NIERPOD_API UClass* Z_Construct_UClass_ABossController_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NierPod();
// End Cross Module References
	void ABossController::StaticRegisterNativesABossController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABossController);
	UClass* Z_Construct_UClass_ABossController_NoRegister()
	{
		return ABossController::StaticClass();
	}
	struct Z_Construct_UClass_ABossController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABossController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_NierPod,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABossController_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABossController_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "BossController.h" },
		{ "ModuleRelativePath", "BossController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABossController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABossController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABossController_Statics::ClassParams = {
		&ABossController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABossController_Statics::Class_MetaDataParams), Z_Construct_UClass_ABossController_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ABossController()
	{
		if (!Z_Registration_Info_UClass_ABossController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABossController.OuterSingleton, Z_Construct_UClass_ABossController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABossController.OuterSingleton;
	}
	template<> NIERPOD_API UClass* StaticClass<ABossController>()
	{
		return ABossController::StaticClass();
	}
	ABossController::ABossController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABossController);
	ABossController::~ABossController() {}
	struct Z_CompiledInDeferFile_FID_Users_admin_Desktop_PodGit_Pod_nier_automata_pod_unreal_engine_master_nier_automata_pod_unreal_engine_master_Source_NierPod_BossController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_admin_Desktop_PodGit_Pod_nier_automata_pod_unreal_engine_master_nier_automata_pod_unreal_engine_master_Source_NierPod_BossController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABossController, ABossController::StaticClass, TEXT("ABossController"), &Z_Registration_Info_UClass_ABossController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABossController), 2157923625U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_admin_Desktop_PodGit_Pod_nier_automata_pod_unreal_engine_master_nier_automata_pod_unreal_engine_master_Source_NierPod_BossController_h_1807334714(TEXT("/Script/NierPod"),
		Z_CompiledInDeferFile_FID_Users_admin_Desktop_PodGit_Pod_nier_automata_pod_unreal_engine_master_nier_automata_pod_unreal_engine_master_Source_NierPod_BossController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_admin_Desktop_PodGit_Pod_nier_automata_pod_unreal_engine_master_nier_automata_pod_unreal_engine_master_Source_NierPod_BossController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
