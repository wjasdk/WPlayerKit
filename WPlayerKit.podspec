#
# Be sure to run `pod lib lint WPlayerKit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'WPlayerKit'
  s.version          = '0.1.2'
  s.summary          = 'P2P音视频播放器SDK库'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
  P2P音视频播放器SDK，轻松实现手机与设备画面实时预览SDK
                       DESC

  s.homepage         = 'https://github.com/wjasdk/WPlayerKit.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'wjasdk' => 'lishutian@wjacloud.com' }
  s.source           = { :git => 'https://github.com/wjasdk/WPlayerKit.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '11.0'

  # s.source_files = 'WPlayerKit/Classes/**/*'
  s.vendored_frameworks = 'WPlayerKit/*.{framework}'
  s.frameworks   = 'Accelerate', 'AudioToolbox', 'AVFoundation', 'CoreData', 'CoreMedia', 'CoreTelephony', 'MetalKit', 'MobileCoreServices', 'OpenAL', 'SystemConfiguration', 'VideoToolbox'

  # s.resource_bundles = {
  #   'WPlayerKit' => ['WPlayerKit/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
