#pragma once

namespace uk { 

    express_tcp_t width() {
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
                       @media( max-width: ${0}px ) {
                    ), size.second ));
                }

                for( auto x=12; x>=1; x-- ){ for( auto y=12; y>=1; y-- ){ if( x >= y ){ continue; }
                    cli.write( regex::format( _STRING_(
                       .uk-child-width-${0}-${1}${2}>:not([class*='uk-width']){ width: calc( ${0}00% / ${1} - 1.2% ); }
                       .uk-width-${0}-${1}${2}                                { width: calc( ${0}00% / ${1} - 1.2% ); }
                    ), x, y, size.first ));
                }}

                for( auto& item : map_t<string_t,string_t>({
                    { "none",    "0px"   },
                    { "small",   "150px" },
                    { "medium",  "300px" },
                    { "large",   "450px" }
                }).data() ){
                    cli.write( regex::format( _STRING_ (
                       .uk-width-${0}${2}     { min-width:${1}; }
                       .uk-max-width-${0}${2} { max-width:${1}; }
                    ), item.first, item.second, size.first ));
                }

                cli.write( regex::format( _STRING_(

                   .uk-child-width-expand${0}>:not([class*='uk-width']){ width: 100vw; }
                   .uk-width-expand${0}                                { width: 100vw; }

                   .uk-child-width-auto${0}>:not([class*='uk-width']){ flex: initial; }
                   .uk-width-auto${0}                                { flex: initial; }

                   .uk-child-width-fill${0}>:not([class*='uk-width']){ width: 100%; }
                   .uk-width-fill${0}                                { width: 100%;  }

                ), size.first ));

                if( size.first != nullptr ){ cli.write( "}" ); }

            }

        });

        return app;
    }

}