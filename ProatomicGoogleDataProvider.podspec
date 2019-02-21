
Pod::Spec.new do |s|
s.name             = 'ProatomicGoogleDataProvider'
s.version          = '0.1.8'
s.summary          = "Proatomic's nice wrapper for the google maps API"
s.description      = "This is a nice wrapper for the google maps API. It exposes 3 methods of the Google API: Fetch directions (routes), Geocoding, fetch places"

s.homepage         = 'http://proatomicdev.com'
s.license          = { :type => 'MIT', :text => 'Copyright 2019 ProAtomic SAC' }
s.author           = { 'Guillermo Sáenz' => 'gsaenz@proatomicdev.com' }
s.source           = { :git => 'https://github.com/ProAtomic/ProatomicGoogleDataProvider.git', :tag => s.version.to_s }

s.ios.deployment_target = '8.0'

s.default_subspecs= [
'Core'
]

s.subspec 'Core' do |ss|
    ss.vendored_frameworks = [
        'ProatomicGoogleDataProvider/Frameworks/ProatomicGoogleDataProvider-Release-iphoneuniversal/ProatomicGoogleDataProvider.framework'
        ]
end

end
