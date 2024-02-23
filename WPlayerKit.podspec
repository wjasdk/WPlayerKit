Pod::Spec.new do |spec|

  spec.name                     = "WPlayerKit"
  spec.version                  = "0.0.2"
  spec.summary                  = "P2P音视频SDK framework"
  spec.description              = <<-DESC
                                  第一个版本
                                  DESC
  spec.homepage                 = "https://github.com/wjasdk/WPlayerKit.git"
  spec.license                  = 'MIT'
  spec.author                   = { "wjasdk" => "lishutian@wjacloud.com" }
  # spec.social_media_url         = 'https://www.linwear.com'
  spec.platform                 = :ios, '11.0'
  spec.source                   = { :git => "https://github.com/wjasdk/WPlayerKit.git", :tag => spec.version.to_s }
  # spec.documentation_url        = 'https://github.com/linwear/Fission_Sdk_iOS/blob/main/README.md'
  spec.requires_arc             = true
  # spec.frameworks               = 'Foundation', 'CoreBluetooth'
  # spec.source_files             = 'Framework/WPlayerKit.framework/Headers/*.{h}'
  spec.ios.vendored_frameworks      = 'Framework/WPlayerKit.framework'
  spec.vendored_libraries       = "libBaseMedia_iOS.a", "libOTELProject.a"

  # spec.public_header_files      = 'Framework/WPlayerKit.framework/Headers/*.{h,m}'

  # spec.subspec 'Headers' do |spec|
  #   spec.source_files           = public_header_files
  #   spec.public_header_files    = public_header_files
  # end

  # spec.subspec 'WPlayerKit' do |rtkota|
  #   rtkota.vendored_frameworks  = 'Framework/WPlayerKit.framework'
  # end
  
  spec.pod_target_xcconfig      = { 
                                  'OTHER_LDFLAGS' => '-lObjC',
                                  }
  
end
