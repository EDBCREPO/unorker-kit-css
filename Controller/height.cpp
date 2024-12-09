#pragma once

namespace uk { 

    express_tcp_t height() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            for( auto& size: map_t<string_t,int>({ 
                { nullptr, 0   },
                { "\\@s",  640 },
                { "\\@m",  960 },
                { "\\@l", 1200 },
                { "\\@2l",1600 }
            }).data() ){

                if( size.first != nullptr ){
                    cli.write( regex::format( _STRING_(
                       @media( max-height: ${0}px ) {
                    ), size.second ));
                }

                for( auto x=12; x>=1; x-- ){ for( auto y=12; y>=1; y-- ){ if( x >= y ){ continue; }
                    cli.write( regex::format( _STRING_(
                       .uk-child-height-${0}-${1}${2}>:not([class*='uk-height']){ height: calc( ${0}00% / ${1} ); }
                       .uk-height-${0}-${1}${2}                                 { height: calc( ${0}00% / ${1} ); }
                    ), x, y, size.first ));
                }}

                for( auto& item : map_t<string_t,string_t>({
                    { "none",    "0px"   },
                    { "small",   "150px" },
                    { "medium",  "300px" },
                    { "large",   "450px" }
                }).data() ){
                    cli.write( regex::format( _STRING_ (
                       .uk-height-${0}${2}     { min-height:${1}; }
                       .uk-max-height-${0}${2} { max-height:${1}; }
                    ), item.first, item.second, size.first ));
                }

                cli.write( regex::format( _STRING_(

                   .uk-child-height-expand${0}>:not([class*='uk-height']){ min-height: 100vh; }
                   .uk-height-expand${0}                                 { min-height: 100vh; }

                   .uk-child-height-fill${0}>:not([class*='uk-height'])  { min-height: 100%; }
                   .uk-height-fill${0}                                   { min-height: 100%; }

                   .uk-child-height-1-1${0}>:not([class*='uk-height'])   { min-height: 100%; }
                   .uk-height-1-1${0}                                    { min-height: 100%; }

                ), size.first ));

                if( size.first != nullptr ){ cli.write( "}" ); }

            }

        });

        return app;
    }

}